# Boggle Solver
In developing the Boggle solver using the C programming language, I followed a systematic approach to ensure efficiency and accuracy. Initially, I focused on creating the linked list file, and testing its functionality to ensure it operated as intended. By successfully implementing the linked list, I laid the groundwork for efficiently handling data and organizing the words encountered during the Boggle-solving process.

Next, I turned my attention to designing and implementing the hashmap, a fundamental data structure that efficiently stores all the valid words. The hashmap played a critical role in optimizing the Boggle solver's performance, enabling fast and constant-time lookups. By strategically mapping words to their corresponding indices in the hashmap, I established a robust foundation for later stages of the solver.

With the linked list and hashmap functioning effectively, I proceeded to tackle the core component of the Boggle solver: the boggle file. Implementing the boggle game required thoughtful consideration of various factors, such as efficiently traversing the Boggle board, finding valid words, and handling various edge cases. Leveraging the capabilities of the linked list and hashmap, I carefully designed the algorithms to explore the Boggle board, identify valid word combinations, and accurately solve the Boggle puzzles.

Throughout the development process, my focus remained on maintaining a well-organized and optimized codebase. I regularly tested each component to ensure that it functioned smoothly and efficiently. By employing this systematic approach, I successfully created a powerful Boggle solver in C that could handle various Boggle puzzles, swiftly identifying and presenting valid words as solutions. The resulting solver represents a testament to the effectiveness of the data structures and algorithms implemented in the project, providing an invaluable tool for Boggle enthusiasts and word-game fans.

## How to compile

To compile `spellcheck`

```
make spellcheck
```

To compile `onePlayerBoggle`

```
make onePlayerBoggle
