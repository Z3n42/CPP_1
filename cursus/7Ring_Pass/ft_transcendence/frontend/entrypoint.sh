#!/bin/sh

# install dependencies
npm install
npm install --save-dev @types/node
npm install @angular-builders/custom-webpack@17 --save-dev
npm install dotenv-webpack --save-dev

# start the Angular development server
ng serve --host 0.0.0.0
