function test(n) {
  let sum = 0,temp=n;
  while (temp) {
    sum += ~~(temp %10);
    temp/=10;
  }
  console.log(sum)
}

test(112)