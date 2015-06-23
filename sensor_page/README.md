### Overall Design

This project is built using [Elm](elm-lang.org). This means that you can build the project from source by running `elm make Main.elm` in the project root. This will generate a new `elm.js` file containing the Elm runtime and all of the code for this application. Hit reload in the browser, and you'll see the new page (if it compiled without any errors); `elm.js` is already included in the `index.html` file in the root of this directory.

### Application Architecture

Understanding a few of the modules in this application should be sufficient for most small-scale edits.
	* Config.elm contains static configuration data for styles, fonts, sizes, urls, etc. If you want to change the way something looks, Config.elm should be the first place you look.
	* View.elm and Main.elm contain most of the UI functions responsible for showing the sensor data streams.
	* EnvSense.elm contains EnvSense-specific configuration. In particular, this file maps sensors to positions on the screen.
	* Chart.elm generates the real-time data graphs and Pointer.elm creates the pointers linking data streams to their originating sensor in the image.

### Building

Build the project by typing `elm make Main.elm` at the command line.

### Notes 

This project makes heavy use of several infix operators:
	<< function composition
	<| function application
	|> function application

Reading the documentation at http://package.elm-lang.org/packages/elm-lang/core/1.1.1/Basics may help demystify this.
