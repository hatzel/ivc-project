## Usage

`make` will generate a sequence of pngs and create a compressed mkv form them using ffmpeg.

Setting the environments variable `SCENE` allows you to select which scene to render.
The lengths of the scenes are set in `scenes.config`.

You could for example render the scene `lol` like this:

```
SCENE=lol make
```

## Structure
Scenes that are actual sequences in the final movie should reside into `scenes/` and objects or utilities that are used in scenes should be placed in `include`.
