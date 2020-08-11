(function (viz) {
    'use strict';

    /*
    ! adattároló 
    */
    viz.data = {};

    viz._debug = false;
    viz._monthly = true;

    viz.TRANS_DURATION = 750;

    // akkor van rá szükség, ha a havi adatokat akarom ábrázolni
    if (viz._monthly) {
        d3.queue()
            .defer(d3.json, 'dataMonthly.json')
            .await(ready);
    } else {
        // akkor van rá szükség, ha havi szinte csoportosított napi adatokat akarok ábrázolni
        const q = d3.queue();
        for (const i of d3.range(0, 192)) {
            q.defer(d3.json, 'dataDailyGroupedByMonths/' + i + '.json');
        }
        q.awaitAll(ready);
    }

    const chartContainer = d3.select('.charts');
    const boundingRect = chartContainer.node().getBoundingClientRect();
    const margin = {
        'top': 100,
        'left': 0,
        'right': 0,
        'bottom': 0
    };
    const width = boundingRect.width + margin.left + margin.right;
    const height = boundingRect.height + margin.top + margin.bottom;

    // akkor van rá szükség, ha a havi adatokat akarom ábrázolni
    function ready(error, data) {
        /* ha valami hiba történt a weboldal betöltése leáll */
        if (error) {
            return console.warn(error);
        }

        if (viz._monthly) {
            /* lementjük az adatokat */
            viz.data = data;
        } else {
            for (const m of data) {
                viz.data[m[0].TIME] = m;
            }
        }

        /* elindítjük a betöltést */
        viz.init();
        setTimeout(function () {
            d3.select('body').attr('class', '');
            d3.select('.overlay').attr('class', 'overlay');
        }, viz.TRANS_DURATION);
    };

    // akkor van rá szükség, ha a havi adatokat akarom ábrázolni
    const groupData = (data) => {
        let summed = {};

        d3.nest().key(function (d) {
            return d.TIME;
        }).entries(viz.data).forEach(function (m) {
            return summed[m.key] = m.values;
        });

        return summed;
    }

    /* egyenkénti ábra méretek */
    const individualPlotSizes = {
        'width': 220,
        'height': 220,
        'margin': {
            'top': 45,
            'left': 40,
            'right': 40,
            'bottom': 75
        }
    };
    const individualPlots = {};

    /* skálaminták */
    /* const scaleX = d3.scaleBand().rangeRound([0, individualPlotSizes.width]).paddingOuter(0).paddingInner(2); */
    const scaleX = d3.scaleLinear().range([0, individualPlotSizes.width]);
    const scaleY = d3.scaleLinear().range([individualPlotSizes.height, 0]);

    const tooltip = d3.select('.tooltip');

    const bisect = d3.bisector(function (d) {
        return d.MATURITY;
    }).left;

    viz.init = function () {
        if (viz._debug) {
            console.log(viz.data);
        }

        /* csoportosítanunk kell az adatokat */
        // akkor van rá szükség, ha a havi adatokat akarom ábrázolni
        let categorized = null;
        if (viz._monthly) {
            categorized = groupData(viz.data);
        } else {
            categorized = viz.data;
        }
        const keys = d3.keys(categorized);

        if (viz._debug) {
            console.log(categorized);
        }

        /* egyenkénti ábrák */
        const individuals = chartContainer.append('div').attr('class', 'individuals');

        const makeIndividuals = (keys) => {
            if (viz._debug) {
                console.log(keys);
            }

            const plots = individuals.selectAll('.individual').data(keys, function (d) {
                return d;
            });

            plots.enter().append('svg')
                .attr('class', 'individual')
                .attr('id', function (d) {
                    return d;
                })
                .attr('width', individualPlotSizes.width + individualPlotSizes.margin.left + individualPlotSizes.margin.right)
                .attr('height', individualPlotSizes.height + individualPlotSizes.margin.top + individualPlotSizes.margin.bottom)
                .append('g').attr('class', 'plot')
                .attr('transform', 'translate(' + individualPlotSizes.margin.left + ', ' + individualPlotSizes.margin.top + ')');

            d3.selectAll('.individual')._groups[0].forEach(function (p) {
                individualPlots[d3.select(p).attr('id')] = {};
                individualPlots[d3.select(p).attr('id')]['plot'] = p;
            });
        }

        makeIndividuals(keys);

        if (viz._debug) {
            console.log(individualPlots);
        }

        /* jelmagyarázat */
        const makeLegend = () => {
            const legendHeight = margin.top;
            const legendWidth = width;

            const legend = chartContainer.insert('div', '.individuals').append('svg').attr('width', legendWidth)
                .attr('height', legendHeight).append('g').attr('class', 'legend');

            legend.append('text')
                .text('December \'07')
                .attr('transform', 'translate(' + legendWidth * 0.03 + ', ' + legendHeight * 0.15 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#ca693f').attr('opacity', .75);
            legend.append('text')
                .text('Recession')
                .attr('transform', 'translate(' + legendWidth * 0.11 + ', ' + legendHeight * 0.15 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#333').attr('opacity', .75);
            legend.append('line')
                .attr('x1', legendWidth * 0.03).attr('x2', legendWidth * 0.1)
                .attr('y1', legendHeight * 0.4).attr('y2', legendHeight * 0.4)
                .attr('stroke', '#999').attr('stroke-width', 6)
                .attr('stroke-linejoin', 'round')
                .attr('stroke-linecap', 'round')
                .attr('opacity', .75);
            legend.append('text')
                .text('Yield Curve line')
                .attr('transform', 'translate(' + legendWidth * 0.11 + ', ' + legendHeight * 0.4 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#333').attr('opacity', .75);
            legend.append('line')
                .attr('x1', legendWidth * 0.03).attr('x2', legendWidth * 0.1)
                .attr('y1', legendHeight * 0.65).attr('y2', legendHeight * 0.65)
                .attr('stroke', '#ca693f').attr('stroke-width', 6)
                .attr('stroke-linejoin', 'round')
                .attr('stroke-linecap', 'round')
                .attr('opacity', .75);
            legend.append('text')
                .text('Inverted Yield Curve line')
                .attr('transform', 'translate(' + legendWidth * 0.11 + ', ' + legendHeight * 0.65 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#333').attr('opacity', .75);
            legend.append('text')
                .text('There\'s one chart for each month, hover over the Yield Curve to inspect exact values')
                .attr('transform', 'translate(' + legendWidth * 0.6 + ', ' + legendHeight * 0.4 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#333').attr('opacity', .75);
            legend.append('text')
                .text('The data refers to AAA-rated Euro-Area central government bonds, and Spot rate')
                .attr('transform', 'translate(' + legendWidth * 0.6 + ', ' + legendHeight * 0.65 + ')')
                .attr('alignment-baseline', 'middle')
                .style('font-size', '1.2rem').style('font-weight', 700)
                .attr('fill', '#333').attr('opacity', .75);
        }

        makeLegend();

        /* tengelyek */
        const makeAxis = (categorized, keys) => {
            for (const k of keys) {
                const current = individualPlots[k];

                const plot = d3.select(current.plot);

                current['scaleX'] = scaleX.copy();
                current['scaleY'] = scaleY.copy();

                const minMaxValue = d3.extent(categorized[k], (c) => c.Value);
                const minMaxMaturity = d3.extent(categorized[k], (c) => c.MATURITY)

                if (viz._debug) {
                    console.log(minMaxValue, minMaxMaturity);
                }

                /* current['scaleX'].domain(d3.range(minMaxMaturity[0], minMaxMaturity[1] + 1)); */
                current['scaleX'].domain(minMaxMaturity);
                current['scaleY'].domain([minMaxValue[0] - .5, minMaxValue[1] + .5]);

                if (viz._debug) {
                    console.log(current['scaleX'].domain(), current['scaleY'].domain());
                }

                const label = plot.insert('g', '.plot').attr('class', 'label')
                    .call((g) => {
                        g.append('text')
                            .text((d) => d3.timeFormat('%B \'%y')(d))
                            .style('font-size', '1.6rem').attr('fill', function (d) {
                                const time = d3.timeFormat('%Y:%m')(d);

                                if (time >= '2007:12' && time <= '2009:06') {
                                    return '#ca693f';
                                }

                                return '#333';
                            })
                            .style('font-weight', 700).attr('opacity', .75);
                    })
                    .attr('transform', function (d) {
                        return 'translate(' + individualPlotSizes.margin.left + ', ' + individualPlotSizes.margin.top / 2 + ')';
                    });

                const xAxis = plot.insert('g', '.plot').attr('class', 'x-axis')
                    .attr('transform', 'translate(' + individualPlotSizes.margin.left + ', ' + (individualPlotSizes.height + individualPlotSizes.margin.top) + ')');

                xAxis.append('line').attr('x1', current['scaleX'](minMaxMaturity[0]) - 1).attr('x2', current['scaleX'](minMaxMaturity[1]) + 1)
                    .attr('y1', 0).attr('y2', 0).attr('stroke', '#333').attr('opacity', .75);

                const xTicks = xAxis.selectAll('.x-ticks')
                    .data([current['scaleX'].domain()[0], Math.floor(d3.mean(current['scaleX'].domain(), (v) => v)), current['scaleX'].domain()[current['scaleX'].domain().length - 1]]);

                xTicks.enter().append('g').attr('class', 'x-ticks')
                    .call((g) => {
                        g.append('line').attr('x1', (d) => current['scaleX'](d)).attr('x2', (d) => current['scaleX'](d))
                            .attr('y1', 0).attr('y2', individualPlotSizes.margin.top / 2).attr('stroke', '#333').attr('opacity', .75);
                    })
                    .call((g) => {
                        g.append('text').text((d) => {
                                return d + '-year';
                            })
                            .attr('x', (d) => current['scaleX'](d)).attr('y', individualPlotSizes.margin.top / 2 + 15)
                            .style('text-anchor', 'middle').attr('fill', '#333').attr('opacity', .75)
                            .style('font-size', '1.3rem')
                            .style('font-weight', 700);
                    });

                const yAxis = plot.insert('g', '.plot').attr('class', 'y-axis')
                    .attr('transform', 'translate(' + individualPlotSizes.margin.left + ', ' + individualPlotSizes.margin.top + ')');

                const yTicks = yAxis.selectAll('.y-ticks')
                    .data([d3.mean(current['scaleY'].domain(), (v) => v), current['scaleY'].domain()[current['scaleY'].domain().length - 1]]);

                yTicks.enter().append('g').attr('class', 'y-ticks')
                    .call((g) => {
                        g.append('line').attr('y1', (d) => current['scaleY'](d)).attr('y2', (d) => current['scaleY'](d))
                            .attr('x1', current['scaleX'].range()[0] + 3).attr('x2', current['scaleX'].range()[1]).attr('stroke', '#333').attr('opacity', .75).attr('stroke-dasharray', '20px');
                    })
                    .call((g) => {
                        g.append('text').text((d) => {
                                return d.toFixed(2) + '%';
                            })
                            .attr('x', current['scaleX'].range()[0] - 35).attr('y', (d) => current['scaleY'](d))
                            .attr('fill', '#333').attr('opacity', .75)
                            .style('font-size', '1.3rem')
                            .attr('alignment-baseline', 'middle')
                            .attr('dx', (d) => {
                                if (d > 0) return '-.25em';
                                else return '-.55em'
                            })
                            .attr('dy', '.1em')
                            .style('font-weight', 700);
                    });
            }
        }

        makeAxis(categorized, keys);

        /* tényleges ábrák */
        const makeViz = (categorized, keys) => {
            for (const k of keys) {
                const current = individualPlots[k];
                const currData = categorized[k];
                const svg = d3.select(current.plot);
                const plot = svg.select('.plot');

                /* hozzáadja a vonalakat */
                plot.append('path')
                    .attr('fill', 'none')
                    .attr('stroke', function () {
                        if (Math.abs(currData[currData.length - 1].Value - currData[0].Value) < 0.3) {
                            return '#ca693f';
                        } else {
                            return '#999';
                        }
                    })
                    .attr('opacity', .75)
                    .attr('stroke-width', 6)
                    .attr('stroke-linejoin', 'round')
                    .attr('stroke-linecap', 'round')
                    .attr('d', function () {
                        return d3.line().x(function (d) {
                            return current['scaleX'](d.MATURITY);
                        }).y(function (d) {
                            return current['scaleY'](d.Value);
                        })(currData)
                    });

                /* egérráviteli effektusok */
                const mouseG = svg.append('g').attr('class', 'mouse-over-effects')
                    .attr('transform', 'translate(' + individualPlotSizes.margin.left + ', ' + individualPlotSizes.margin.top + ')');

                /* létrehoz egy vertikális vonalat, hogy kövesse az egeret */
                mouseG.append('path').attr('class', 'mouse-line')
                    .attr('stroke', '#333')
                    .attr('stroke-width', 3)
                    .attr('opacity', 0)
                    .attr('stroke-linejoin', 'round')
                    .attr('stroke-linecap', 'round');

                const mouseC = mouseG.append('circle').attr('class', 'mouse-circle').attr('r', 8)
                    .attr('stroke', '#333').attr('fill', 'none').attr('stroke-width', 3).attr('opacity', 0);

                svg.on('mousemove', function () {
                    const mouseCoords = d3.mouse(this);
                    const maturity = Math.floor(current['scaleX'].invert(mouseCoords[0]));

                    if (maturity > 10 || maturity == null) return;

                    svg.select('.mouse-circle').attr('transform', function () {
                        const idx = bisect(currData, maturity);

                        svg.select('.mouse-line').attr('d', function () {
                            const data = 'M' + current['scaleX'](currData[idx].MATURITY) + ',' + (individualPlotSizes.height) +
                                ' ' + current['scaleX'](currData[idx].MATURITY) + ',' + 0;

                            return data;
                        });

                        tooltip.html('<p>Maturity: ' + maturity + '-year,</p><p>Yield: ' + currData[idx].Value + '%</p>');


                        return 'translate(' + current['scaleX'](currData[idx].MATURITY) + ', ' + current['scaleY'](currData[idx].Value) + ')';
                    });

                    svg.select('.mouse-line').attr('opacity', .5);
                    svg.select('.mouse-circle').attr('opacity', .5);
                    tooltip.style('left', (d3.event.pageX + 20) + 'px');
                    tooltip.style('top', (d3.event.pageY - 20) + 'px');
                });
                svg.on('mouseleave', function () {
                    svg.select('.mouse-line').attr('opacity', 0);
                    svg.select('.mouse-circle').attr('opacity', 0);
                    tooltip.style('left', '-9999px');
                });
            }
        }

        makeViz(categorized, keys);
    }
}(window.viz = window.viz || {}));