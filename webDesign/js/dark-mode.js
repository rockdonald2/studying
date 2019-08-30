const darkmodeToggle = document.querySelector("#invert");

const doc = document.documentElement;

const classToggleFn = className => e => {
    if (e.target.checked) {
        doc.classList.add(className);
    }
    else {
        doc.classList.remove(className);
    }
}

darkmodeToggle.addEventListener('input', classToggleFn('inverted'));