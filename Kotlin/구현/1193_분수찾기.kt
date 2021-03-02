/* BOJ - 1193 분수찾기 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun findFraction(order: Int): String {
    var count = 1
    var orderNumber = order

    do {
        if (orderNumber <= count) {
            val numerator = if (count % 2 == 0) orderNumber else count - orderNumber + 1
            val denominator = if (count % 2 == 0) count - orderNumber + 1 else orderNumber
            return "$numerator/$denominator"
        } else {
            orderNumber -= count
            count += 1
        }
    } while (true)
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val order = bufferedReader.readLine().toInt()

    println(findFraction(order))
    bufferedReader.close()
}