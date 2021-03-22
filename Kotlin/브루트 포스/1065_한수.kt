/* BOJ - 1065 한수 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun isHansu(number: Int) =
        with(number.toString()) { (this[0] - this[1]) == (this[1] - this[2]) }

fun countHansu(number: Int) = run {
    if (number in 1..99) {
        number
    } else {
        var count = 99
        for (n in 100..number) {
            if (isHansu(n)) {
                count += 1
            }
        }
        count
    }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val number = reader.readLine().toInt()
    print(countHansu(number))
}