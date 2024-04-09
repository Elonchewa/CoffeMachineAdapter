const main = document.getElementByID('main');
const head = docunmet.getElementByID('header');
const StartBrew = document.getElementByID('StartBrew');

StartBrew.addEventListener('click', BrewAlert);

function BrewAlert() {
  let x = document.getElementById('CoffeeMug');
  let displaySetting = x.style.display;
  if (displaySetting == 'block') {
    x.style.display = 'none';
  }
  else {
    x.style.display = 'block';
  }
    console.log('Your Coffee is now brewing');
    $(document).mousemove(function (e) {
      $("#CoffeeMug").css({
        left: e.pageX,
        top: e.pageY + 25
      });
    });

}