# Ejercicio 4

## a)

$T(n) = T(n-2)+5 =$
$ = T(n - 4) + 5 + 5= T(n-6) + 5 + 5 + 5= \ ... \ = $
$ = T(n - 2k) + 5 * k  $
Suponiendo n par:
$ n - 2k = 0 \iff k = \frac{n}{2}$
entonces:
    $ T(n) = T(0) + \frac{5}{2} * n = Θ(n)$

## b)

$ T(n) = T(n - 1) + n $
$ = T(n - 2) + (n - 1) + n = T(n - 3) + (n - 2) + (n-1) + n = ... =$
$ = T(n - (n - 1)) + 2 + 3 + ... + n = $
$ = T(1) + \sum_{k=2}^{n} k = T(1) + \frac{n(n+1)}{2} - 1$
$ = T(1) + \frac{n^2+n}{2} - 1 = T(1) + \frac{1}{2}(n^2+n) = \Theta(n^2)$

## c)

$ T(n) = T(n-1) + \sqrt{n} $
$ = T(n - 2) + \sqrt{n-1} + \sqrt{n}$
$ = ... $
$ = T(n- (n - 1)) + \sum_{k=2}^{n} \sqrt{k}$
$ = T(1) + \sum_{k=2}^{n} \sqrt{k} $

Y podemos ver que

$\sum_{k=2}^{n} \sqrt{k} \leq \int_{2}^{n}\sqrt{x} \ dx = \frac{2}{3} x^\frac{3}{2} \bold{|}_{2}^{n} = \frac{2}{3} (n^\frac{3}{2} - 2) = Θ(n^\frac{3}{2})$

Y ahora

$ T(n) = T(1) + \sum_{k=2}^{n} \sqrt{k} = Θ(n^\frac{3}{2}) $

## d)

$ T(n) = T(n - 1) + n^2 $
$ = T(n - 2) + (n - 1)^2 + n^2 $
$ ...$
$ = T(1) + \sum_{k=2}^{n} k^2 \leq \int_{2}^{n}x^2 \ dx = \frac{x^3}{3} \bold{|}_{2}^{n} = \frac{1}{3} (n^3 - 8) = Θ(n^3)$

$∴ T(n) = Θ(n^3)$

## e)

$ T(n) = 2T(n-1)$
$ = 2(2 T(n - 2)) = ... = 2^{n-1} T(1) = Θ(2^n)$

## f)

$T(n) = T(n/2) + n$

Se puede aplicar Teorema Maestro. Veamos:
$a=1, \ b=2, \ f(n) = n $

Luego veamos:
$k = log_2(1) = 0$
$y \ f(n) = n = Ω(n^1)$ y $1 > log_2(1) = 0$
Veamos si se cumple $1 * f(\frac{n}{2}) \leq r * f(n), k < 1 \ y >>n$.
$ f(\frac{n}{2}) \leq r * f(n)$
$ \frac{n}{2} \leq r * n $
lo cual es cierto para r = 0.8
$∴ T(n) = Θ(n)$

## g)

$T(n) = T(\frac{n}{2}) + \sqrt{n}$

$ a = 1, b = 2, f(n) = \sqrt{n} $

$log_b(a) = log_2(1) = 0$

$f(n) = \sqrt{n} \in Ω(n^{1/2})$ y $ \frac{1}{2} > 0 = log_2(1) $
Entonces estamos ante el caso 3. Resta ver si se cumple
$a * f(\frac{n}{b}) \leq k * f(n)$
$ 1 * f(\frac{n}{2}) \leq k f(n) \iff \sqrt{\frac{n}{2}} \leq k \sqrt{n}$ para algun k < 1.
Esto se cumple para k = 0.9 entonces,
$ T(n) = \Theta(\sqrt{n}) $

## 10)

$ T(n) = 2T(\frac{n}{2}) + log \ n $
$ a = 2, b = 2, f(n) = log \ n $
$ log_2(2) = 1 $
$ f(n) = log \ n = O(n^{0.999}) $ y $ 0.999 < log_2(2) = 1 \longrightarrow T(n) = \Theta(n^1) = \Theta(n) $
