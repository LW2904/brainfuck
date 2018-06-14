## brainfuck

A [brainfuck](http://www.muppetlabs.com/~breadbox/bf/) interpreter written in JS. Ironic, really. At least it doesn't depend on anything.

Following the inofficial [Portable Brainfuck](http://www.muppetlabs.com/~breadbox/bf/standards.html) implementation standard as written by Brian Reiter.

Implementation-defined details:
- All cells hold 64 bit floating point integers (largest: 2^53 - 1) which may be negative.
- Characters are represented by their UTF16 code.
- The pointer may not be smaller than zero.
- If input is expected but stdin empty, the program will block and wait for input.

### API

```javascript
const { bf } = require('@sturmwalzer/brainfuck');

// Move value of cell zero (which is read from stdin) to the next cell.
bf(', [ -> +< ] .');
```

```typescript
interface BFCallback {
    index: number,
    cells: number[],
    pointer: number,
}

function bf(instr: string | NodeJS.ReadableStream, cb?: () => BFCallback)
```

The first argument may also be a stream, note that the complete stream will first be buffered into memory, though. An optional callback function may also be passed, which will be called with some metadata once all instructions have been executed.

```javascript
const { createReadStream } = require('fs');

bf(createReadStream('./brainfuck.txt'), (meta) => {
    console.log(`last pointer index: ${meta.pointer}, cells: ${meta.cells}`);
});
```