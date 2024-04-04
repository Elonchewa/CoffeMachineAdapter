const main = document.getElementByID('main');
const head = docunmet.getElementByID('header');
const StartBrew = document.getElementByID('StartBrew');
let jogoat = 1;

StartBrew.addEventListener('click', BrewAlert);

let i = 0;
while (i < 10) {
$(document).mousemove(function (e) {
    $("#CoffeeMug").css({
      left: e.pageX,
      top: e.pageY + 25
    });
});
}
function BrewAlert() {
    console.log('Your Coffee is now brewing');
    

}