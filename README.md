CasparCG Server 2.0.7 MAV Edition
=================================

Foreword
--------

The update of the codebase to 2.0.7 is courtesy of [@krzyc](https://github.com/krzyc),
I (@jstarpl) have updated this repository so that any future forks and work on this code
can use his work and the latest CasparCG codebase. You can find the latest compiled
binaries on the [@krzyc download page](https://github.com/krzyc/CasparCG-Server/releases/).

Please report bugs and proposals on GitHub:
https://github.com/krzyc/CasparCG-Server/issues

Forum thread regarding this edition is avaliable at:
http://casparcg.com/forum/viewtopic.php?f=3&t=1310

System Requirements
-------------------

This does require a preety beefy machine, although machines as specified by SVT
(http://casparcg.com/wiki/CasparCG_Server#System_Requirements) should do just fine
at least for one (in- and out-) channel.

Installation
------------

Follow the instalation procedures from README.txt. If this is your first
installation of a CasparCG Server, please try installing a normal version,
and learn how to use CasparCG first. I recomend using the MAV Edition only for
people already fluent in CasparCG.

CONFIGURATION
-------------

The casparcg.config has been modified, to specifically target the MAV edition.
Note the two channels. The minimal configuration for the MAV edition requires
at least two channels: one for ingest and another one for output. This usually
means two Decklink cards: one for input, and another one for output.

Beyond that you can have multiple input and output channels, in various
configurations. Always have only one replay buffer per ingest channel.

 * Configure all ingest channels as empty channels with proper system modes
   (f.g. PAL or 1080i50000). Leave the consumers tag empty.

 * Configure all output channels as porper channels, like you normally would,
   f.g. with Decklink consumers.

 * Start the server

 * Play the input from your ingest decklink card on your ingest channel:

	play 1 decklink 1

 * Add the replay consumer to your ingest channel:

	add 1 replay test-replay

   The "test-replay" is a file-name for your replay buffer. Two files will be
   created in your CasparCG "media" folder: a TEST-REPLAY.MAV file and a
   TEST-REPLAY.IDX file. The first one is the video essence, and the second
   one is a manifest and index file. Should you copy your replay buffers,
   always copy both files.

 * Play your replay buffer on your output channel:

	play 2 test-replay

 * Voila! You have your own replay system.

You can seek within your replay buffer using the CALL ACMP 2.0 command:

This will seek to the 100th frame in the replay buffer:

	call 2 seek 100

This will seek to the 100th frame from the end in the replay buffer

    call 2 seek |100

This will move the playhead of your replay 50 frames forward

    call 2 seek +50

This will move the playhead of your replay 50 frames backward

    call 2 seek -50

You can limit length of played clip:

	call 2 length 500
	
This will limit length of played clips to 500 frames
	
You can also change the speed of your playback (this is somewhat wonky
right now):

Will make the playback go at normal speed:

    call 2 speed 1

Will make the playback go backwards at twice the normal speed

    call 2 speed -2

Will make the playback go at half the speed

    call 2 speed 0.5

Will make the playback go backwards at 3/4 of normal speed

    call 2 speed -0.75
	
Will pause the playback (is the same as setting speed to 0)

	call 2 pause

You can enable or disable audio:

Will enable audio

	call 2 audio 1
	
Will disable audio

	call 2 audio 0

AMCP REFERENCE
--------------

	ADD channel REPLAY filename

	PLAY channel filename SPEED speed SEEK [+/-/|/]frames LENGTH franes AUDIO 0/1

	CALL channel SPEED speed

	CALL channel SEEK [+/-/|/]frames

	CALL channel LENGTH frames

	CALL channel AUDIO 0/1
