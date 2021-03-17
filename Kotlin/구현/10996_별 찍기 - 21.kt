/* BOJ - 10996 별 찍기 - 21 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun isEven(number: Int) = number % 2 == 0
fun isOdd(number: Int) = number % 2 == 1

fun printStar(length: Int) {
    val stringBuilder = StringBuilder()
    if (length == 1) {
        stringBuilder.append("*\n")
    } else {
        for (row in 1..(length * 2)) {
            for (column in 1..length) {
                if (isEven(row) && isOdd(column) || isOdd(row) && isEven(column)) {
                    stringBuilder.append(" ")
                } else {
                    stringBuilder.append("*")
                }
            }
            stringBuilder.append("\n")
        }
    }
    print(stringBuilder)
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val n = reader.readLine().toInt()
    printStar(n)
}