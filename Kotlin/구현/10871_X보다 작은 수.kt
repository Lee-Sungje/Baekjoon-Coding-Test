/* BOJ - 10871 X보다 작은 수 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val inputValues = bufferedReader.readLine().split(" ").map { it.toInt() }
    val permutation = bufferedReader.readLine().split(" ").map { it.toInt() }

    val stringBuilder = StringBuilder()
    for (element in permutation) {
        if (element < inputValues.last()) {
            stringBuilder.append("$element ")
        }
    }
    println(stringBuilder)
}