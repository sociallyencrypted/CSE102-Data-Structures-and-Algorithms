# Huffman Encoding
## Min-Heap
Min-heap was used to implement this huffman encoding/decoding system. It was used to generate a huffman tree by calling the minimum two elements of the heap and adding their frequencies to create an internal node, till the size of the heap became 1
## Size difference
Running `du -h in.txt` and `du -h out.txt` shows a major size difference in files, signifying a compression of approximately 3 times:

```bash
➜  Assignment git:(master) ✗ du -h in.txt 
 12K    in.txt
```

```bash
➜  Assignment git:(master) ✗ du -h out.txt
4.0K    out.txt
```

## Metadata
The first line of `out.txt` stores `n`, the number of unique charachters identified. The next line stores `r`, the number of charachters to be read. The next `n` lines store the huffman codes in the format: `charachter: code`. This is followed by the encoded text.