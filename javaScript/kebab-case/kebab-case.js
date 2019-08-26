let kebabCase = (str) => {
    let regEx = /\s/gi;

    return str.replace(regEx, "-").toLowerCase();
}

let str = "kebab case thiS";
console.log(kebabCase(str));
