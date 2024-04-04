const main = document.getElementByID('main');
const head = docunmet.getElementByID('header');
const StartBrew = document.getElementByID('StartBrew');

StartBrew.addEventListener('click', BrewAlert);

function dogChase() {

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