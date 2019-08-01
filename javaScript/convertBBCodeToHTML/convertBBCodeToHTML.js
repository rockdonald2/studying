'use strict'

function convertBBCodeToHTML(str) {
    let html = ""; // string to store final html code

    // iterate through all the chars from the string
    for (let letter = 0; letter < str.length;) {
        switch (str[letter]) {
            case "[": {
                letter++; // iterate to next char
                switch (str[letter]) {
                    case "b": {
                        html += "<strong>";
                        break;
                    }
                    case "i": {
                        html += "<em>";
                        break;
                    }
                    case "u": {
                        html += "<span style=\"text-decoration: underline;\">";
                        break;
                    }
                    case "s": {
                        html += "<del>";
                        break;
                    }

                    case "/": {
                        letter++; // iterate to next char
                        switch (str[letter]) {
                            case "b": {
                                html += "</strong>";
                                break;
                            }
                            case "i": {
                                html += "</em>";
                                break;
                            }
                            case "u": {
                                html += "</span>";
                                break;
                            }
                            case "s": {
                                html += "</del>";
                                break;
                            }
                        }
                    }
                }

                letter += 2; // iterate after next bracket
                continue;
            }

            default: {
                html += str[letter];
                break;
            }
        }
        letter++; // iterate normal
    }

    return html;
}

function getBBCode() {
    let str = document.getElementById("input").value;

    document.getElementById("p").innerHTML = convertBBCodeToHTML(str);
}