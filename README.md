# wasm-click-counter
A POC for using Emscripten to generate WASM from C with a HTML5 front-end and Puppeteer for integration testing (unit testing TBD).

## Windows installation
The main dependency is [Emscripten](https://emscripten.org/), which happens to depend on Node and Python which are also used in this project. On Windows, I used [Chocolatey](https://community.chocolatey.org/packages/emscripten) to install Emscripten with [this script](https://github.com/aminya/chocolatey-emscripten) (which can also be used without Chocolatey). Once `emsdk` is available, I followed the setup shown [in the Emscripten docs](https://emscripten.org/docs/getting_started/downloads.html):

```powershell
cd C:\Users\<your user name>\AppData\Local\emsdk
./emsdk install latest
./emsdk activate latest
.\C:\Users\<your user name>\AppData\Local\emsdk\emsdk_env.ps1 # export `emcc`, `npm`, `node`, `python`, etc to the path
```

Once you have a prompt with the exported path using `emsdk_env.ps1`, clone or download this repo and run `cd ~/path/to/wasm-click-counter`.

One-time setup: `npm i` to install Jest, Nodemon and Puppeteer to `node_modules`.

## Windows build/run/test
Make sure you've exported the path using `.\emsdk_env.ps1`.

These are the build/run/test commands from `package.json`:
- `npm run build` compiles the WASM to the `dist` directory and copies all `.html` and `.js` files to the `dist` directory (there's no bundling step for the front-end).
- `npm run start` starts the Python web server. Navigate to <http://localhost:8000/dist/click-counter.html> to use the application.
- `npm run test` runs Jest/Puppeteer. This will fail if localhost from the above step isn't running.

But the typical development workflow is to run `npm run start`, then run `nodemon` to automatically run `npm run build && npm run test` whenever a source file changes.

## Resources
Unit testing possibilities:
- <https://github.com/Snaipe/Criterion>
- <https://github.com/rubenvannieuwpoort/c_unit_tests>

