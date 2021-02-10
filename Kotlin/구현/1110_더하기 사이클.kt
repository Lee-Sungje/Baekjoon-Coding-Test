/* BOJ - 1110 더하기 사이클 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val originNumber = bufferedReader.readLine().let { input ->
        if (input.length < 2) "0$input" else input
    }
    
    var answer = 0
    var newNumber = originNumber
    do {
        newNumber = run {
            val first = newNumber.first() - '0'
            val last = newNumber.last() - '0'
            "$last${(first + last) % 10}"
        }
        answer++
    } while (newNumber != originNumber)

    println(answer)
    bufferedReader.close()
}