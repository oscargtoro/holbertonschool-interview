#!/usr/bin/node

const request = require('request');
const reqUrl = 'https://swapi-api.hbtn.io/api/films/'.concat(process.argv.slice(2));
request(
  reqUrl,
  function (error, response, body) {
    if (error) {
      console.log(error);
    }
    const resp = JSON.parse(body);
    for (const key in resp.characters) {
      request(
        resp.characters[key],
        function (error, response, body) {
          if (error) {
            console.log(error);
          }
          const character = JSON.parse(body);
          console.log(character.name);
        }
      );
    }
  }
);
