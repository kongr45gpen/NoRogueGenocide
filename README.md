## NoRogueGenocide Project Overview

This is the NoRogueGenocide plugin for BZFlag.

It prevents rogues from getting or using the Genocide (G) flag. 

It operates under 3 different modes:

- Default mode: Prevents rogues from getting the G flag, sending them an
                informative message every time they try to pick one up.

- Silent mode: Prevents rogues from getting the G flag, without sending
               any messages.

- Seamless mode: Although rogues can still take the geno flag, their shots
                 will not act as geno shots and will only kill one person,
                 as opposed to the whole team.

To activate the silent mode add 'silent' or 'quiet' as a command line argument,
while 'seamless' or 'hidden' will can be used to enable the seamless mode.
