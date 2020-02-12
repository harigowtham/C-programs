curryedMultiply = (n) => (m) => n * m
curryedMultiply(3)(4) === 12 // true

multiply = (n, m) => curryedMultiply(n)(m)
multiply(3, 4) === 12 // true

console.log(multiply(2,4))
console.log(multiply(2)(4))
