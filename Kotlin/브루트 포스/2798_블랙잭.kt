/* BOJ - 2798 블랙잭 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun blackjack(target: Int, cards: MutableList<Int>): Int {
    var maximumSum = 0
    for (first in 0..cards.lastIndex) {
        for (second in first + 1..cards.lastIndex) {
            for (third in second + 1..cards.lastIndex) {
                val pickedCards = cards[first] + cards[second] + cards[third]
                if (pickedCards in (maximumSum + 1)..target) {
                    maximumSum = pickedCards
                }
            }
        }
    }
    return maximumSum
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val answer = StringTokenizer(reader.readLine()).run {
        val n = this.nextToken().toInt()
        val m = this.nextToken().toInt()
        val cards = mutableListOf<Int>().also { cards ->
            StringTokenizer(reader.readLine()).run {
                repeat(n) { cards.add(nextToken().toInt()) }
            }
        }
        blackjack(m, cards)
    }
    println(answer)
}