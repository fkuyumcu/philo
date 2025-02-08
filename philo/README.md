# 🍽️ Philosophers - Dining Philosophers Problem

A **C-based solution** to Dijkstra's classic **"Dining Philosophers" Problem**, implemented as part of the **École 42 curriculum**. This project demonstrates concurrent programming, synchronization, and deadlock avoidance techniques.

---

## 📖 Problem Description

The **Dining Philosophers Problem** is a classic synchronization problem in computer science, originally formulated by **Edsger Dijkstra** in 1965. It illustrates the challenges of resource allocation and deadlock avoidance in concurrent systems.

### Scenario:
- Five philosophers sit around a circular table.
- Each philosopher has a plate of spaghetti.
- There is a single fork placed between each pair of adjacent philosophers.
- To eat, a philosopher must acquire **both the left and right forks**.
- Philosophers alternate between **thinking** and **eating**.

### Challenges:
1. **Deadlock**: If all philosophers pick up their left fork simultaneously, no philosopher can acquire a right fork, leading to a deadlock.
2. **Starvation**: Ensuring that every philosopher gets a chance to eat without being indefinitely blocked.

---

## 🛠️ Solution Overview

This project implements a solution to the Dining Philosophers Problem using **mutexes and threads** in C. The solution ensures:
- **Deadlock Avoidance**: By introducing constraints on how forks are acquired.
- **Starvation Prevention**: By ensuring that all philosophers eventually get a chance to eat.
- **Concurrency**: Using threads to simulate the behavior of each philosopher.

### Key Features:
- **Thread-based Simulation**: Each philosopher is represented by a separate thread.
- **Mutex Locks**: Forks are protected by mutexes to ensure safe access.
- **State Tracking**: Each philosopher's state (thinking, eating, or hungry) is displayed in real-time.
- **Scalable Design**: The solution can be adapted for `n` philosophers.

---

## 🚀 How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/philo.git
   ```
2. **Navigate to the Project Directory**:
   ```bash
   cd philo
   ```
3. **Compile the Program**:
   ```bash
   make
   ```
4. **Run the Program**:
   ```bash
   ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [optional: number_of_meals]
   ```
   Example:
   ```bash
   ./philo 5 800 200 200 7
   ```
   This simulates 5 philosophers, with:
   - `800 ms` as the time before a philosopher dies if not eating.
   - `200 ms` as the time it takes to eat.
   - `200 ms` as the time it takes to sleep.
   - Each philosopher eats at least `7` times before the program ends.

---

## 🧠 Design and Implementation

### Data Structures:
- **Philosopher Struct**: Represents each philosopher's state, including their ID, forks, and timers.
- **Mutex Array**: Protects each fork to ensure mutual exclusion.

### Algorithm:
1. Each philosopher thread alternates between **thinking** and **eating**.
2. A philosopher attempts to pick up both forks (left and right) using mutex locks.
3. If successful, the philosopher eats for a specified time, then releases the forks.
4. If a philosopher cannot acquire both forks, they wait and retry.

### Synchronization:
- **Mutexes**: Ensure that only one philosopher can hold a fork at a time.
- **Timers**: Track how long a philosopher has been thinking or eating to prevent starvation.

---

## 📊 Example Output

```
1: Philosopher 1 is thinking.
2: Philosopher 2 has taken a fork.
3: Philosopher 3 is eating.
4: Philosopher 4 has taken a fork.
5: Philosopher 5 is thinking.
...
```

---

## 📂 Repository Structure

```
philo/
├── src/                # Source files
│   ├── main.c          # Entry point
│   ├── philosopher.c   # Philosopher logic
│   ├── utils.c         # Utility functions
│   └── Makefile        # Build script
├── includes/           # Header files
├── README.md           # Project documentation
└── LICENSE             # License file
```

---

## 🛠️ Dependencies

- **C Compiler** (e.g., `gcc`)
- **Make** (for building the project)

---

## 🤝 Contributions

Contributions are welcome! If you have suggestions, improvements, or bug fixes, feel free to:
1. Open an **issue**.
2. Submit a **pull request**.

---

## 📜 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

This version of the `README.md` is more visually appealing, structured, and informative. It provides a clear overview of the project, how to use it, and its design, making it easier for others to understand and contribute.
