/* BOJ - 8393 합 */

package boj

fun main() {
    val n: Int = readLine()?.toInt() ?: 1
    var sum: Int = 0

    for (number in 1..n) {
        sum += number
    }
    println(sum)
}