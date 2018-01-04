include scenes.config
.PHONY: default clean render movie watch play

MODE ?= fast
SCENE ?= title
POVSETTINGS = +KFI1 +KFF12724 +KF12724.0 -GR +GF -GD -GS -GW
START_FRAME ?= 1
END_FRAME ?= $($(SCENE)_LENGTH)
OUTDIR = output

FRAMES = $(shell echo "{$(START_FRAME)..$(END_FRAME)}")
FRAME_TARGETS = $(shell printf "$(OUTDIR)/$(SCENE)%05d.png " $(FRAMES))

ifeq ($(MODE),high)
	POVQUALITY = +W1920 +H1080 +Q9 +A +R2
else ifeq ($(MODE),fast)
	POVQUALITY = +W320 +H180 +Q9 -A
else ifeq ($(MODE),superfast)
	POVQUALITY = +W320 +H180 +Q5 -A
endif

default: $(FRAME_TARGETS) encode

$(OUTDIR)/$(SCENE)%.png:
	mkdir -p $(OUTDIR)
	povray  +O$(OUTDIR)/$(SCENE).png +SF$* +EF$* $(POVSETTINGS) $(POVQUALITY) scenes/$(SCENE).pov

encode:
	ffmpeg -framerate 24 -i $(OUTDIR)/$(SCENE)%05d.png -y -r 24 \
		-vcodec libx264 -pix_fmt yuv420p -preset veryslow -crf 22 -vf 'fade=t=out:st=160:d=4' \
		-threads 0 $(OUTDIR)/$(SCENE).mkv

clean:
	rm -rf $(OUTDIR)/*

play:
	mpv --osd-level 3 --osd-fractions $(OUTDIR)/$(SCENE).mkv
