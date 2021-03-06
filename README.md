# ft_printf

```C
int	ft_printf( const char *, ... );
```

## Convertion specification

Usage :
> %[[flags](#flag-directives)][[width](#width-specification)][[.precision](#precision-specification)][type](#type-conversion-specifier)

### Type conversion specifier

| Format specifier | Suitable type | Output format |
| --- | --- | --- |
| `c` | `char` | Single-bytes charcater. |
| `s` | `char *` | Single-byte or multi-byte character string |
| `p` | `void *` | Address in hexadecimal digits. |
| `d` | `int` | Signed decimal integer. |
| `i` | `int` | Signed decimal integer. |
| `u` | `unsigned int` | Unsigned decimal integer. |
| `x` | `unsigned int` | Unsigned hexadecimal integers (using "`abcdef`"). |
| `X` | `unsigned int` | Unsigned hexadecimal integers (using "`ABCDEF`"). |
| `%` | `NONE` | Display the `%` character |

### Flag directives

The first optional field in a conversion specification contains flag directives, zero or more flag characters that specify output justification and control output of signs, blanks, leading zeros, and hexadecimal prefixes. More than one flag directive may appear in a conversion specification, and the flag characters can appear in any order.

| Flag | Description |
| --- | --- |
| `-` | Left justify |
| `0` | Pad with leading `0`|
| `#` | If used with `x` or `X`, prefix a non-zero value with `0x` or `0X` |
| `+` | Use `+` to prefix the output value if it's of a positive value (signed only) |
| blank (' ') | Use a blank to prefix the output value if it's signed and positive. |

### Width specification

The width argument is a non-negative decimal integer that controls the minimum number of characters that are output. If the number of characters in the output value is less than the specified width, blanks are added to the left or the right of the values—depending on whether the left-alignment flag (`-`) is specified—until the minimum width is reached. If width is prefixed by `0`, leading zeros are added to integer until the minimum width is reached.

If the width specification is an asterisk (`*`), an `int` argument from the argument list supplies the value.

```C
printf( "%0*d", 4, 50 ); /* 0050 is output */
```

### Precision specification

It consists of a period (`.`) followed by a non-negative decimal integer that, depending on the conversion type, specifies the number of string characters or the number of decimal places to be output.

If precision is specified as 0, and the value to be converted is 0, the result is no characters output, as shown in this example:
```C
printf( "%.0d", 0 ); /* No characters output */
```

If the width specification is an asterisk (`*`), an `int` argument from the argument list supplies the value.
```C
printf( "%.*s", 5, "Bonjour" ); /* "Bonjo" is output */
```

#### How precision values affect type

| Type | Meaning | Default |
| --- | --- | --- |
| `c` | The precision has no effect. | Character is printed |
| `d`, `i`, `u`, `x`, `X` | The precision specifies the minimum number of digits to be printed. If the number of digits in the argument is less than precision, the output value is padded on the left with zeros. | Default precision is 1 |
| `s` | The precision specifies the maximum number of characters to be printed. | Characters are printed until a null character is found |


## Installation :

This will also install the `libft` (needed)
```BASH
git clone https://github.com/Alienxbe/New42Printf.git printf &&
git clone https://github.com/Alienxbe/libft.git printf/libft
```

## Sources

+ [Microsoft documentation](https://docs.microsoft.com/en-us/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions)

## Licenses & copyright

© Ykman Martin, School 19
