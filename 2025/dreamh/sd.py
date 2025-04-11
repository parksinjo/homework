import sys

memory = bytearray.fromhex(
    '7233647930203730'
    '2064336275363f00'
)

def write_n(ptr: bytes, length: int):
    sys.stdout.buffer.write(ptr[:length])
    sys.stdout.buffer.flush()

length = 0xf
ptr = memory
write_n(ptr, length)

