// var xhr = new XMLHttpRequest();
// xhr.open('GET', 'https://swapi.co/api/films/', true);
// xhr.send();
// // xhr.onreadystatechange = function() {
// //     console.log(xhr.readyState);
// //     console.log(xhr.status);
// //     console.log(xhr.statusText);
// // }
// xhr.onload = function() {
//     if (xhr.status == 200){
//         var films = JSON.parse(xhr.response);
//         var filmList = new Array(films.results[0].title, films.results[1].title, films.results[2].title, films.results[3].title, films.results[4].title, films.results[5].title, films.results[6].title);
//         for(var i = 0; i < filmList.length; i++) {
//             //var a = document.createElement("a");
//             var x = document.createElement("LI");
//             var t = document.createTextNode(filmList[i]);
//             // a.appendChild(x).appendChild(t);
//             x.appendChild(t);
//             document.getElementById("items").appendChild(x);
//         }
//         var li = document.getElementsByTagName('li');
//         for(var i = 0; i < li.length; i++){
//             li[i].className = "list-group-item";
//         }
//     }
//     else {
//         console.log(xhr.statusText);
//     }
// }

function loadFilms() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://swapi.co/api/films/', true);
    xhr.send();
    xhr.onload = function() {
        if (xhr.status == 200){
            var films = JSON.parse(xhr.response);
            var filmList = new Array(films.results[0].title, films.results[1].title, films.results[2].title, films.results[3].title, films.results[4].title, films.results[5].title, films.results[6].title);
            for(var i = 0; i < filmList.length; i++) {
                //var a = document.createElement("a");
                var x = document.createElement("LI");
                var t = document.createTextNode(filmList[i]);
                // a.appendChild(x).appendChild(t);
                x.appendChild(t);
                document.getElementById("items").appendChild(x);
            }
            var li = document.getElementsByTagName('li');
            for(var i = 0; i < li.length; i++){
                li[i].className = "list-group-item";
            }
        }
        
        else {
            alert(xhr.statusText);
        }
    }
}

function characters() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://swapi.co/api/films/', true);
    xhr.send();
    xhr.onload = function() {
        if (xhr.status == 200){
            var films = JSON.parse(xhr.response);
            var filmCharacters = new Array(films.results[0].characters.length, films.results[1].characters.length,films.results[2].characters.length, films.results[3].characters.length, films.results[4].characters.length, films.results[5].characters.length, films.results[6].characters.length);
            var li = document.getElementsByClassName('list-group-item');
            for(var i = 0; i < filmCharacters.length; i++) {
                var a = document.createElement("span");
                a.className = "badge badgePrimary badgePill";
                a.style.cssFloat = "right";
                a.style.backgroundColor = "#000000";
                var b = document.createTextNode(" " + films.results[i].characters.length + " ");
                li[i].appendChild(a).appendChild(b);
            }


        }
    }
}



function planets() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://swapi.co/api/films/', true);
    xhr.send();
    xhr.onload = function() {
        if (xhr.status == 200){
            var films = JSON.parse(xhr.response);
            var filmPlanets = new Array(films.results[0].planets.length, films.results[1].planets.length,films.results[2].planets.length, films.results[3].planets.length, films.results[4].planets.length, films.results[5].planets.length, films.results[6].planets.length);
            var li = document.getElementsByClassName('list-group-item');
            for(var i = 0; i < filmPlanets.length; i++) {
                var a = document.createElement("span");
                a.className = "badge badgePrimary badgePill";
                a.style.cssFloat = "right";
                a.style.backgroundColor = "#15afb2";
                var b = document.createTextNode(" " + films.results[i].planets.length + " ");
                li[i].appendChild(a).appendChild(b);
            }


        }
    }
}


function starships() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://swapi.co/api/films/', true);
    xhr.send();
    xhr.onload = function() {
        if (xhr.status == 200){
            var films = JSON.parse(xhr.response);
            var filmStarships = new Array(films.results[0].starships.length, films.results[1].starships.length,films.results[2].starships.length, films.results[3].starships.length, films.results[4].starships.length, films.results[5].starships.length, films.results[6].starships.length);
            var li = document.getElementsByClassName('list-group-item');
            for(var i = 0; i < filmStarships.length; i++) {
                var a = document.createElement("span");
                a.className = "badge badgePrimary badgePill";
                a.style.cssFloat = "right";
                a.style.backgroundColor = "#d12988";
                var b = document.createTextNode(" " + films.results[i].starships.length + " ");
                li[i].appendChild(a).appendChild(b);
            }


        }
    }
}


function characters2() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', 'https://swapi.co/api/films/', true);
    xhr.send();
    xhr.onload = function() {
        if (xhr.status == 200){
            var films = JSON.parse(xhr.response);
            var filmCharacters = new Array(films.results[0].characters, films.results[1].characters ,films.results[2].characters , films.results[3].characters , films.results[4].characters , films.results[5].characters , films.results[6].characters );
            var li = document.getElementsByClassName('list-group-item');
            for(var i = 0; i < 7; i++) {
                var nL = document.createElement("UL"); //create sub list
                nL.className = "list-group"; //give class
                var l;
                var o;
                for(var z = 0; z < films.results[i].characters.length; z++){
                    l = document.createElement('LI');
                    l.className = "list-group-item";
                    o = document.createTextNode(films.results[i].characters[z]);
                    nL.appendChild(l).appendChild(o);
                }    //add characters to list creating li
                var a = document.createElement("span");
                a.className = "badge badgePrimary badgePill";
                a.style.cssFloat = "right";
                a.style.backgroundColor = "#000000";
                var b = document.createTextNode(" " + films.results[i].characters.length + " ");
                li[i].appendChild(nL).appendChild(a).appendChild(b);
            }


        }
    }
}





// function filmCharacters(filmNum) {
//     var xhr = new XMLHttpRequest();
//     xhr.open('GET', 'https://swapi.co/api/films/'+ filmNum, true);
//     xhr.send();
//     xhr.onload = function() {
//         if (xhr.status == 200){
//             var filmData = JSON.parse(xhr.response);
//             // for(var i = 0; i < filmCharacters.length; i++) {
//             //     var a = document.createElement("span");
//             //     a.className = "badge badgePrimary badgePill";
//             //     a.style.cssFloat = "right";
//             //     a.style.backgroundColor = "#000000";
//             //     var b = document.createTextNode(films.results[i].characters.length);
//             //     li[i].appendChild(a).appendChild(b);
//             // }


//         }
//     }
// }



loadFilms();