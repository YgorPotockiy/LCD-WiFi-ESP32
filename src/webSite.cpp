#include "webSite.h"

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="main.css">
    <title>LCD control</title>
</head>
<body>
    <h1 id="lcdControlText">LCD control</h1>
    <div id="formDiv">
    <form action="/submit" method="get">
        <small id="smallText">Max length is 16 characters</small> <br>
        <input id="firstRayInput" type="text" name="text" maxlength="16" required>
        <input class="submitButton" type="submit" value="Send"> <br>
    </form>
    <form action="/submit" method="get">
        <input id="secondRayInput" type="text" name="text2" maxlength="16" required>
        <input class="submitButton" type="submit" value="Send"> <br>
    </form>
    <br><button id="clearButton" onclick="fetch('/refresh/button')">Clear display</button>
    </div>

</body>
</html>)rawliteral" ;

const char main_css[] PROGMEM = R"rawliteral(
#firstRayInput {
    color: white;
    font-family:'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
    border: green;
    border-style: solid;
    border-bottom: 0;
    border-width: 12px;
    font-size: 20px;
    width: 300px;
    height: 40px;
    background-color: rgb(0, 89, 255);
}

body {
    text-align: center;
    background-color: rgb(29, 185, 247);
}

#clearButton {
    height: 60px;
    width: 120px;
    background-color: aquamarine;
    color: black;
    font-size: 20px;
}

#lcdControlText {
    color: white;
    font-style: bold;
}

#smallText {
    color: white;
    font-size: 20px;
    margin-left: -70px;
}

.submitButton {
    color: white;
    font-family:'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
    font-size: 20px;
    background-color: rgb(1, 204, 126);
    border-color: rgb(0, 255, 34);
    width: 60px;
    height: 30px;

}
#secondRayInput {
    color: white;
    font-family:'Franklin Gothic Medium', 'Arial Narrow', Arial, sans-serif;
    border: green;
    border-style: solid;
    border-top: 0;
    border-width: 12px;
    font-size: 20px;
    width: 300px;
    height: 40px;
    background-color: rgb(0, 89, 255);
}

@media screen and (max-width: 800px) {
    #firstRayInput, #secondRayInput {
        width: 60%;
    }
    
}

@media screen and (max-width: 600px) {
    #firstRayInput, #secondRayInput {
        width: 80%;
    }
}

@media screen and (max-width: 400px) {
    #firstRayInput, #secondRayInput {
        width: 100%;
    }
}

@media screen and (max-width: 300px) {
    #firstRayInput, #secondRayInput {
        width: 100%;
        font-size: 16px;
    }

})rawliteral" ;