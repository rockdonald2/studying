(function (viz) {
    'use strict';

    /* általános változók */
    const chartContainer = d3.select('.chart');
    const boundingRect = chartContainer.node().getBoundingClientRect();
    const margin = {
        'top': 100,
        'left': 75,
        'right': 25,
        'bottom': 25
    };
    const width = boundingRect.width - margin.left - margin.right;
    const height = boundingRect.height - margin.top - margin.bottom;

    /* hozzáadjuk az ábratartót */
    const svg = chartContainer.append('svg')
        .attr('width', width + margin.left + margin.right)
        .attr('height', height + margin.top + margin.bottom);

    const plot = svg.append('g')
        .attr('class', 'plot')
        .attr('transform', 'translate(' + margin.left + ', ' + margin.top + ')');

    const tooltip = chartContainer.select('.tooltip');

    /* beolvassuk az adatokat */
    d3.queue()
        .defer(d3.json, 'data.json')
        .await(ready);

    function ready(error, data) {
        /* ha valami hiba történt a beolvasáskor, álljon le */
        if (error) {
            return console.warn(error);
        }

        /* ábralétrehozási folyamat elindítása */
        viz.makeViz(data);

        /* 1mp-s késleltetés után eltűnteti a fedőt */
        setTimeout(function () {
            d3.select('body').attr('class', '');
            d3.select('.overlay').attr('class', 'overlay');
        }, 1000);
    }

    viz.makeViz = function (data) {
        /* tengelyek */
        const scaleDay = d3.scaleBand().rangeRound([0, width]).domain(d3.range(1, 32)).padding(0.05);
        const scaleMonth = d3.scaleBand().rangeRound([height, 0]).domain(d3.range(12, 0, -1)).padding(0.05);
        const colorScale = d3.scaleSequential().interpolator(d3.interpolatePlasma).domain(d3.extent(data, function (d) {
            return d.ratio;
        }));

        const xAxis = svg.append('g').attr('class', 'x-axis')
            .attr('transform', 'translate(' + (margin.left + 5) + ', ' + margin.top / 1.35 + ')');
        xAxis.append('text').text('Day').style('font-size', '1.4rem')
            .style('font-weight', 700).attr('opacity', .75);
        const xTicks = xAxis.selectAll('.x-ticks').data(scaleDay.domain())
            .enter().append('g')
            .call(function (g) {
                g.append('text')
                    .attr('id', function (d) {
                        return 'x-' + d;
                    })
                    .text(function (d) {
                        return d;
                    }).attr('x', function (d, i) {
                        return scaleDay(d) + 12;
                    }).attr('y', 23)
                    .style('font-weight', 700).attr('opacity', .75)
                    .style('font-size', '1.2rem')
                    .style('text-anchor', 'middle')
                    .attr('fill', '#333');
            });

        const yAxis = svg.append('g').attr('class', 'y-axis')
            .attr('transform', 'translate(' + margin.left / 1.3 + ', ' + margin.top + ')');
        yAxis.append('text').text('Month').style('font-size', '1.4rem')
            .style('font-weight', 700).attr('opacity', .75)
            .attr('text-anchor', 'end');
        const yTicks = yAxis.selectAll('.y-ticks').data(scaleMonth.domain())
            .enter().append('g')
            .call(function (g) {
                g.append('text')
                    .attr('id', function (d) {
                        return 'y-' + d;
                    })
                    .text(function (d) {
                        return d;
                    }).attr('x', 5).attr('y', function (d, i) {
                        return scaleMonth(d) + 26;
                    })
                    .style('font-weight', 700).attr('opacity', .75)
                    .style('font-size', '1.2rem')
                    .style('text-anchor', 'middle')
                    .attr('fill', '#333');
            });

        /* jelmagyarázat */
        const legend = svg.append('g').attr('class', 'legend')
            .attr('transform', 'translate(' + margin.left + ', 10)');
        const legendImg = legend.append('image').attr('href', 'plasma.png')
            .attr('height', 15).attr('width', 225).attr('preserveAspectRatio', 'none')
            .attr('x', (width - margin.left) * 0.7)
            .attr('y', margin.top * 0.3);
        legend.append('text').text('(less common) ' + colorScale.domain()[0].toFixed(2))
            .style('font-weight', 700).attr('opacity', .75)
            .style('font-size', '1.2rem')
            .attr('alignment-baseline', 'middle')
            .attr('fill', '#333')
            .attr('x', (width - margin.left) * 0.59)
            .attr('y', margin.top * 0.39)
        legend.append('line').attr('x1', (width - margin.left) * 0.65 + 54).attr('x2', (width - margin.left) * 0.65 + 54)
            .attr('y1', margin.top * 0.47).attr('y2', margin.top * 0.28)
            .attr('stroke', '#333')
            .attr('stroke-width', 2)
            .attr('opacity', .75);
        legend.append('text').text(colorScale.domain()[1].toFixed(2) + ' (more common)')
            .style('font-weight', 700).attr('opacity', .75)
            .style('font-size', '1.2rem')
            .attr('alignment-baseline', 'middle')
            .attr('fill', '#333')
            .attr('x', (width - margin.left) * 0.92)
            .attr('y', margin.top * 0.39)
        legend.append('line').attr('x1', (width - margin.left) * 0.86 + 54).attr('x2', (width - margin.left) * 0.86 + 54)
            .attr('y1', margin.top * 0.47).attr('y2', margin.top * 0.28)
            .attr('stroke', '#333')
            .attr('stroke-width', 2)
            .attr('opacity', .75);

        legend.append('text').text('Label refers to birth ratio relative to average, average = 1822')
            .style('font-weight', 700).attr('opacity', .75)
            .style('font-size', '1.2rem')
            .attr('dy', '.075em')
            .attr('alignment-baseline', 'middle')
            .attr('fill', '#333')
            .attr('x', (width - margin.left) * 0.15)
            .attr('y', margin.top * 0.39)

        /* ábra */
        const sqs = plot.selectAll('.sqs').data(data, function (d) {
            return d.date;
        });

        sqs.enter().append('rect').attr('class', 'sqs')
            .attr('id', function (d) {
                return d.date;
            })
            .attr('x', function (d) {
                return scaleDay(parseInt(d.date.split('/')[0]));
            })
            .attr('y', function (d) {
                return scaleMonth(parseInt(d.date.split('/')[1]));
            })
            .attr('rx', 2)
            .attr('ry', 2)
            .attr('width', function (d) {
                return scaleDay.bandwidth();
            })
            .attr('height', function (d) {
                return scaleMonth.bandwidth();
            })
            .attr('fill', function (d) {
                return colorScale(d.ratio);
            })
            .attr('stroke-width', 2)
            .attr('stroke', 'transparent')
            .attr('opacity', .75)
            .style('cursor', 'pointer')
            .on('mousemove', function (d) {
                d3.select(this).transition().duration(150).attr('opacity', 1);

                tooltip.select('.tooltip--heading').html(d.date);
                tooltip.select('.tooltip--info').html('<p>On average during this 23-year period <span>' + d.dailyAverages.toFixed(0) + '</span> live-births have occurred on this date.</p>');
                tooltip.select('.tooltip--info span').style('color', colorScale(d.ratio));

                xAxis.select('#x-' + parseInt(d.date.split('/')[0])).attr('fill', '#fcd025');
                yAxis.select('#y-' + parseInt(d.date.split('/')[1])).attr('fill', '#fcd025');

                if (d3.event.pageX >= width * 0.85) {
                    tooltip.style('left', (d3.event.pageX - parseInt(tooltip.style('width')) - 20) + 'px');
                } else {
                    tooltip.style('left', (d3.event.pageX + 20) + 'px');
                }
                tooltip.style('top', (d3.event.pageY - 20) + 'px');
            })
            .on('mouseleave', function (d) {
                d3.select(this).transition().duration(150).attr('opacity', .75);

                xAxis.select('#x-' + parseInt(d.date.split('/')[0])).attr('fill', '#333');
                yAxis.select('#y-' + parseInt(d.date.split('/')[1])).attr('fill', '#333');

                tooltip.style('left', '-9999px');
            });

        const labels = plot.selectAll('.label').data(data, function (d) {
            return d.date;
        });

        labels.enter().append('text')
            .text(function (d) {
                return d.ratio.toFixed(2);
            })
            .attr('x', function (d) {
                return scaleDay(parseInt(d.date.split('/')[0])) + scaleDay.bandwidth() / 2;
            })
            .attr('y', function (d) {
                return scaleMonth(parseInt(d.date.split('/')[1])) + scaleMonth.bandwidth() / 2;
            })
            .attr('text-anchor', 'middle')
            .attr('dy', '.33em')
            .attr('fill', '#333')
            .style('font-size', '1.2rem')
            .style('font-weight', 700)
            .attr('opacity', .75)
            .style('pointer-events', 'none');
    }
}(window.viz = window.viz || {}));