#!/usr/bin/node

const reqUrl = 'https://swapi-api.hbtn.io/api/films/'.concat(process.argv.slice(2));
const request = require('request');
request(
  reqUrl,
  async function (error, response, body) {
    if (error) {
      console.log(error);
    }
    const resp = JSON.parse(body);
    for (const url of resp.characters) {
      await new Promise(function (resolve, reject) {
        request(
          url,
          function (error, response, body) {
            if (error) {
              console.log(error);
              reject(error);
            } else {
              const character = JSON.parse(body);
              console.log(character.name);
              resolve();
            }
          }
        );
      });
    }
  }
);
