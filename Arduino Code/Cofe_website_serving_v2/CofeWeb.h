#ifndef WEBPAGE_H
#define WEBPAGE_H

const char* webpage = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>COFFE HOME</title>
    <link rel="stylesheet" href="HomePage.css">
    <script src="HomePage.js"> </script>

  <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.3.1/jquery.min.js">
  </script>

</head>
<body>
  <img id="CoffeeMug" class="CoffeeMug" src="IMAGES\CoffeeMug.jpg"
  style="position:absolute;z-index: 10;display:none;" width="125px" height="125px">


<h1> Welcome, User</h1>
<div class="dhdcontainer">
<a href="/servo/start"><button type = 'Button'  id='StartBrew' onclick="BrewAlert()"> Start Brew </button></a>
</div>
<img src="Images/setting.jpg" alt="home button">
<h1>SETTINGS</h1>
<div class="dhdcontainer">
<form action="/action_page.php">
    <label for="appt">Select a time:</label>
    <input type="time" id="appt" name="appt">
    <input type="submit">
  </form>
  <script>
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

    // Get the current date and time
    var currentDate = new Date();

    // Extract individual components
    var hours = currentDate.getHours();
    var minutes = currentDate.getMinutes();
    var seconds = currentDate.getSeconds();

    var time = hours+minutes+seconds

    </script>
    <style>
      body {
    background-color: #6f4e37;
    }

  h1 {
    text-align: center;
    color: #eeebd0;
  }

.dhdcontainer {
  display: flex;
  flex: 1;
  flex-wrap: wrap;
  justify-content: center;
  align-items: center;
  padding: 1.5vh;
}

#StartBrew {
  background-color: #071e22;
border-color: #eeebd0;
color: #eeebd0;
border-radius: 1.5vh;
width: 25vh;
height: 5vh;
text-align: center;
display: inline;
font-size: 2.5vh;
cursor: pointer;
}

#StartBrew:hover {
  background-color: #071e22;
border-color: #eeebd0;
color: #eeebd0;
border-radius: 1.5vh;
width: 25vh;
height: 5vh;
text-align: center;
display: inline;
font-size: 2.5vh;
cursor: pointer;
}

img {
  display: block;
  height: 25vh;
  width: 25vh;
  flex-direction: column;
  border-radius: 50vh;
}
input {
  background-color: #071e22;
  color: #a5a392;
}
    </style>
</div>
</body>
</html>
)=====";

#endif