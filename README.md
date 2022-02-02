# click-counter
A POC for using emscripten to generate WASM from C with a HTML front-end and Puppeteer for integration testing (unit testing TBD).

## Installation/dependencies
- emscripten (and export `emcc` to the path)
- node
- python

## Building/running
- run `npm i` to install Puppeteer and Jest
- run `npm run build` to compile the WASM to the `dist` directory
- run `npm run start` to start the Python web server on localhost
- run `npm run test` to run Puppeteer on the live code

### Unit testing possibilities
- <https://github.com/Snaipe/Criterion>
- <https://github.com/rubenvannieuwpoort/c_unit_tests>

