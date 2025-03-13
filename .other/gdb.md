In GDB, you can make it follow only **thread 1** by using the following command:

```gdb
set scheduler-locking on
thread 1
```

### Explanation:
- `set scheduler-locking on`: This ensures that only the selected thread is allowed to run when you continue execution. Other threads will be blocked.
- `thread 1`: Switches to thread 1 so that all debugging commands (like stepping and continuing) apply only to this thread.

If you also want GDB to stop on breakpoints only in **thread 1**, you can set thread-specific breakpoints like this:

```gdb
break my_function thread 1
```

Let me know if you need more details! 🚀
