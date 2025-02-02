# libadx-nds

ADX decoder/player for Nintendo DS homebrew, written using [BlocksDS](https://github.com/blocksds/sdk)

## Information

When playing an ADX file, it is decoded on the ARM7, allowing to run game logic on the ARM9 uninterrupted.

The ADX quality has been tested up to 48000 Hz 128 kbps, with no lag.<br/>
Higher kbps quality may be possible, but it has not been tested.

## Credits
* LibADX Dreamcast library (c)2011-2013 Josh PH3NOM Pearson
* Built on top of [NDS Helix-MP3 decoder](https://adshomebrewersdiary.blogspot.com/2012/06/mp3-streaming-on-arm7.html) code by sverx, which is a fixed version of [hacker013's original code](https://gbadev.net/forum-archive/thread/23/17859.html)
