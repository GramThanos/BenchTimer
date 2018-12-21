[![latest version](https://img.shields.io/badge/latest%20version-v0.2-green.svg?style=flat-square)](https://github.com/GramThanos/BenchTimer/releases/latest)
![Windows build](https://img.shields.io/badge/window%20build-pass-blue.svg?style=flat-square)
![Linux build](https://img.shields.io/badge/linux%20build-pass-blue.svg?style=flat-square)
![Mac build](https://img.shields.io/badge/mac%20build-not--available-red.svg?style=flat-square)

# BenchTimer
A C benchmark timer library

This library let you easily record task timings during execution. [[Download]](https://github.com/GramThanos/BenchTimer/releases)

Both Windows and Linux support.

___

### Usage
```C
// Create a timer
benchtimer* timer = benchtimer_create();
// Start the timer
benchtimer_start(timer);

// Execute task / code
foo();
moo();

// Stop the timer
benchtimer_stop(timer);
// Get recording timing in seconds
double seconds = benchtimer_get(timer);
// Print data
printf("Task executed in %lf milliseconds\n", seconds * 1000);
```

___

### Examples
You can find full examples codes inside the "examples" folder.
[Go to examples](https://github.com/GramThanos/BenchTimer/tree/master/examples)

___

### Contact me

Contact me to leave a feedback or to express your thoughts.

[Open an issue](https://github.com/GramThanos/BenchTimer/issues)

[Send me a mail](mailto:gramthanos@gmail.com)

___

### License

This project is under [The MIT license](https://opensource.org/licenses/MIT).
We do although appreciate attribute.

Copyright (c) 2018 Grammatopoulos Athanasios-Vasileios

___

[![GramThanos](https://avatars2.githubusercontent.com/u/14858959?s=42&v=4)](https://github.com/GramThanos)
[![DinoDevs](https://avatars1.githubusercontent.com/u/17518066?s=42&v=4)](https://github.com/DinoDevs)
