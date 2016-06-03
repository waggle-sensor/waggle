## Testing Procedure

__This test sets the Wagman clock based on the clock of the QA computer. It is essential
that the QA computer has correct time set on it__

*  Initialize the Wagman RTC by issuing command *make program*
*  After initializing the board, unplug USB and Power to Wagman.
*  After 30 seconds, power the Wagman back up and plug the USB cable into it.
*  Continue with the test by issuing the command *make test* and follow the on-screen prompts.

__To exit the screen session created for the test, press Control+a, followed by k and y.__
