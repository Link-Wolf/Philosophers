<div id="top"></div>

<div align="center">
	<a href="https://github.com/Link-Wolf/Philosophers" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=Link-Wolf&message=Philosophers&color=blue&logo=github&style=for-the-badge" alt="Link-Wolf - Philosophers"></a>
	<a href="https://"><img src="https://img.shields.io/badge/42_grade-100_%2F_100-brightgreen?style=for-the-badge" alt="42 grade - 125 / 100"></a>
	<a href="https://"><img src="https://img.shields.io/badge/Year-2022-ffad9b?style=for-the-badge" alt="Year - 2022"></a>
	<a href="https://github.com/Link-Wolf/Philosophers/stargazers"><img src="https://img.shields.io/github/stars/Link-Wolf/Philosophers?style=for-the-badge&color=yellow" alt="stars - Philosophers"></a>
	<a href="https://github.com/Link-Wolf/Philosophers/network/members"><img src="https://img.shields.io/github/forks/Link-Wolf/Philosophers?style=for-the-badge&color=lightgray" alt="forks - Philosophers"></a>
	<a href="https://github.com/Link-Wolf/Philosophers/issues"><img src="https://img.shields.io/github/issues/Link-Wolf/Philosophers?style=for-the-badge&color=orange" alt="issues - Philosophers"></a>
	<a href="https://www.apple.com/macos/" title="Go to Apple homepage"><img src="https://img.shields.io/badge/OS-macOS-blue?logo=apple&logoColor=white&style=for-the-badge&color=9cf" alt="OS - macOS"></a>
</div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a>
    <img src="https://www.42mulhouse.fr/wp-content/uploads/2022/06/logo-42-Mulhouse-white.svg" alt="Logo" width="192" height="80">
  </a>

  <h3 align="center">Philosophers</h3>

  <p align="center">
	  <em>I’ve never thought philosophy would be so deadly.</em><br/>
	Learn the basics of threading a process, how to make threads, and discover the mutex
    <br />
    <br />
    <a href="https://github.com/Link-Wolf/Philosophers/issues">Report Bug</a>
    ·
    <a href="https://github.com/Link-Wolf/Philosophers/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<div align="center">
  <a>
    <img src="https://media.discordapp.net/attachments/453159761639112706/998949433800654918/unknown.png" alt="FdF header">
  </a>
</div>
</br>

The philosophers' problem is the classical problem of synchronization which says that `n` philosophers are sitting around a circular table and their job is to think and eat in turn.</br>
A bowl of noodles is placed at the center of the table along with `n` forks between each philosopher</br>
To eat a philosopher needs both their right and left forks. A philosopher can only eat if both their immediate left and immediate right forks are available
</br>In case either of their immediate left or immediate right fork is not available then they put down their other fork and start thinking again.
If the philosopher can eat, they do then they'll sleep before thinking again

The goal of the project is to simulate this problem by using C `threads`, and with custom parameters
- `number_of_philosophers` : the number of philosophers and also the number of forks
- `time_to_die` : if a philosopher doesn’t start eating `time_to_die` milliseconds after starting his last meal or the beginning of the simulation, he dies
- `time_to_eat` : The time (in milliseconds) it takes for a philosopher to eat. During that time he will need to keep the two forks
- `time_to_sleep` : The time (in milliseconds) the philosopher will spend sleeping
- **[Optional]** `number_of_times_each_philosopher_must_eat` : if every philosopher eat at least `number_of_times_each_philosopher_must_eat` times, the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher

Each philosopher should be a `thread`, to avoid philosophers duplicating forks we have to protect the forks state with a
`mutex` for each of them and philosophers don’t speak with each other.
Philosophers should avoid dying, so the program should organize each philosopher time, and print any change of status of a philosopher as :
```
  [timestamp_in_ms] X ([has taken a fork] / [is eating] / [is sleeping] / [is thinking] / [died])
```

### Bonus features

In the bonus version, all the forks are in the middle of the table</br>
They have no states in memory but the number of available forks is represented by
a `semaphore`</br>
And each philosopher should be a process and the main process should not be a philosopher


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

Because it's a simple C program, there isn't much to say here

### Prerequisites

Having a C compiler like cc, gcc or clang

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/Link-Wolf/Philosophers.git
   ```
2. Compile Philosophers
   ```sh
   cd Philosophers/philo; make
   ```
3. Execute the program with parameters described <a href="#about-the-project">here</a> and see how it works
   ```sh
   ./philo 10 800 400 200
   ```
   *it should run forever*
   
   Or stop the program with `number_of_times_each_philosopher_must_eat`
   ```sh
   ./philo 10 800 400 200 15
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

Test this Philosophers with the parameters you want, with or without a stopper !

#### Example
```sh
   ./philo 3 800 400 200 3
```

#### Output

```
	0 0 is thinking
	0 0 has taken a fork
	0 0 has taken a fork
	0 0 is eating
	0 1 is thinking
	0 2 is thinking
	400 0 is sleeping
	400 1 has taken a fork
	400 1 has taken a fork
	400 1 is eating
	600 0 is thinking
	800 1 is sleeping
	800 2 has taken a fork
	800 2 has taken a fork
	800 2 is eating
	1000 1 is thinking
	1200 2 is sleeping
	1200 0 has taken a fork
	1200 0 has taken a fork
	1200 0 is eating
	1400 2 is thinking
	1600 0 is sleeping
	1600 1 has taken a fork
	1600 1 has taken a fork
	1600 1 is eating
	1800 0 is thinking
	2000 1 is sleeping
	2000 2 has taken a fork
	2000 2 has taken a fork
	2000 2 is eating
	2200 1 is thinking
	2400 2 is sleeping
	2400 0 has taken a fork
	2400 0 has taken a fork
	2400 0 is eating
	2600 2 is thinking
	2800 0 is sleeping
	2800 1 has taken a fork
	2800 1 has taken a fork
	2800 1 is eating
	3000 0 is thinking
	3200 1 is sleeping
	3200 2 has taken a fork
	3200 2 has taken a fork
	3200 2 is eating
```

#### Example where a philosopher die
```sh
   ./philo 3 500 400 200
```

#### Output

```
	0 0 is thinking
	0 2 is thinking
	0 0 has taken a fork
	0 0 has taken a fork
	0 0 is eating
	0 1 is thinking
	400 0 is sleeping
	400 1 has taken a fork
	400 1 has taken a fork
	400 1 is eating
	500 2 died
```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Add the bonus
- [x] Add back to top links

See the [open issues](https://github.com/Link-Wolf/Philosophers/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Mail : xxxxxxx@student.42mulhouse.fr

Project Link: [https://github.com/Link-Wolf/Philosophers](https://github.com/Link-Wolf/Philosophers)

<p align="right">(<a href="#top">back to top</a>)</p>
