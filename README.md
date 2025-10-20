# Praktikum Automotive Software Engineering WS25/26

## Unit 1 - Embedded Programming

### Configuring Pins

```c
SIU.PCR[24].R = 0x0200; /* configures as output */
SIU.PCR[60].R = 0x0100; /* configures as input */
SIU.PCR[66].R = 0x2500; /* configures as analog pin */
```

### Reading Input Pin Value

```c
value = SIU.GPDI[x].R // digital
int pot_value = (ADC0.CDR[5].R & 0x00000FFF) // analog
```

### Set Output Pin Value

```c
SIU.GPDO[x].R = <value>
```

### Timers

```c
PIT_ConfigureTimer(timer_channel, interval); // configure timer (in milliseconds)
PIT_StartTimer(timer_channel); // start timer
PIT_StopTimer(timer_channel); // stop timer
```

ISRs (Interrupt Service Routine) are defined in `PIT_Channel_1`, `PIT_Channel_2` and `PIT_Channel_3` accordingly.
