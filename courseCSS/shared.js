var backdrop = document.querySelector('.backdrop');
var modal = document.querySelector('.modal');
var selectPlanButtons = document.querySelectorAll('.plan .plan__button');

for (let i = 0; i < selectPlanButtons.length; i++) {
    selectPlanButtons[i].addEventListener('click', function() {
        modal.classList.add('open');
        backdrop.style.display = 'block';
        setTimeout(function() {
            backdrop.classList.add('open');
        }, 200);
    });
}

function closeModal() {
    if (modal) {
        modal.classList.remove('open');
    }
    backdrop.style.display = 'none';
    setTimeout(function() {
        backdrop.classList.remove('open');
    }, 200);
}
var modalNoButton = document.querySelector('.modal__action--negative');

backdrop.addEventListener('click', function() {
    mobileNav.classList.remove('open');
    closeModal();
});

if (modalNoButton) {
    modalNoButton.addEventListener('click', closeModal);
}

var toggleButton = document.querySelector('.toggle-button');
var mobileNav = document.querySelector('.mobile-nav');

toggleButton.addEventListener('click', function() {
    mobileNav.classList.add('open');
    setTimeout(function() {
        backdrop.classList.add('open');
    }, 200);
});

var ctaButton = document.querySelector('.main-nav__item--cta');

ctaButton.addEventListener('animationstart', (event) => {
    console.log('Animation started', event);
});

ctaButton.addEventListener('animationend', (event) => {
    console.log('Animation ended', event);
});

ctaButton.addEventListener('animationiteration', (event) => {
    console.log('Animation iteration', event);
});