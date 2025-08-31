### Usage

```bash
chmod +x ./run.sh
./run.sh "link with whatever you want"
```

#### Example

main.c

```c
    extern int factorial(int);

    int main() {

        factorial(5);

        return 0;
    }
```

Then run:

```bash
    ./run.sh Recursion/factorial.c
```
