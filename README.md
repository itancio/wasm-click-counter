# wasm-click-counter
A POC for using Emscripten to generate [WASM](https://webassembly.org/) from C with a HTML5 front-end and [Puppeteer](https://github.com/puppeteer/puppeteer) for integration testing (unit testing TBD).

## Windows installation
The main dependency is [Emscripten](https://emscripten.org/), which happens to depend on Node and Python which are also used in this project. On Windows, I used [Chocolatey](https://community.chocolatey.org/packages/emscripten) to install Emscripten with [this script](https://github.com/aminya/chocolatey-emscripten), running `choco install emscripten -y`. The script can also be used without Chocolatey. Once `emsdk` is available, I followed the setup shown [in the Emscripten docs](https://emscripten.org/docs/getting_started/downloads.html):

```powershell
./emsdk install latest
./emsdk activate latest

# export `emcc`, `npm`, `node`, `python`, etc to the path
.\C:\Users\<your user name>\AppData\Local\emsdk\emsdk_env.ps1
```

Once you have a prompt with the exported path using `emsdk_env.ps1`, clone or download this repo and run `cd ~/path/to/wasm-click-counter`.

Download `utest.h`, e.g. `wget https://raw.githubusercontent.com/sheredom/utest.h/master/utest.h -O tests/unit/utest.h`.

Finally, run `npm i` from the `wasm-click-counter` directory to install Jest, Nodemon and Puppeteer to `node_modules`.

## Windows build/run/test

### Back-end (C)

Add tests in `tests/unit` and run `make test` in that directory. Make sure you've downloaded [`utest.h`](https://github.com/sheredom/utest.h).

### Front-end (HTML/WASM)
Make sure you've exported the path using `.\emsdk_env.ps1` described in the above section.

These are the build/run/test commands from `package.json`:
- `npm run build` compiles the WASM from the `src/click-counter.c` file to the `dist` directory and copies all `.html` and `.js` files to the `dist` directory (there's no bundling step for the front-end yet).
- `npm run start` starts the Python web server. Navigate to <http://localhost:8000/dist> to use the application.
- `npm run test` runs Jest/Puppeteer. This will fail if localhost from the above step isn't running.

The typical development workflow is to run `npm run start`, then run `nodemon` to automatically execute `npm run build && npm run test` whenever a source file changes.

## Deploying to GitHub pages
I'm using the `gh-pages` branch and the `docs` folder to deploy to <https://ggorlen.github.io/wasm-click-counter>. Run `git checkout gh-pages && git merge master`, build the project if needed and run `npm run deploy` to copy `dist` to `docs` (`docs` is a special name that GitHub can use as a root pages directory). Then push up to GitHub.

## Resources
Unit testing possibilities:
- <https://github.com/sheredom/utest.h> (using this one for now)
- <https://github.com/rubenvannieuwpoort/c_unit_tests>
- <https://github.com/Snaipe/Criterion>
- <https://github.com/google/googletest>
- <https://github.com/libcheck/check>
- <https://github.com/cgreen-devs/cgreen>
- <https://p403n1x87.github.io/running-c-unit-tests-with-pytest.html>

Shrinking code size: <https://hacks.mozilla.org/2018/01/shrinking-webassembly-and-javascript-code-sizes-in-emscripten/>

