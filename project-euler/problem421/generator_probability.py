from sympy import totient, primerange, divisor_count

# There are totient(p - 1) generators for Z_p^* and so let us consider a
# probabilistic algorithm for finding any such generator. We wish to
# determine an asymptotic for totient(p - 1) / (p - 1). We desire for
# this probability to be rather high, as there is a 1/prob expected value
# of trials we need to find the generator. As long as this 1/prob is
# not asymptotic to p itself, we should be golden.

# I don't really know a whole lot of good resources for this, so we might as
# well just compute it for ourselves and see, right?

# As for checking whether or not the sampled value is a generator,
# this can depend on the number of divisors of p - 1, so let's see
# how large this grows

prob = 0

primes = 0
N = 10 ** 6

for p in primerange(2, N + 1):
    prob += float(totient(p - 1)) / (p - 1)

    primes += 1

print("Average probability of finding a generator:", prob / primes)

# This is right around 0.374, which is very desirable
