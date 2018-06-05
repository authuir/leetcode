func numJewelsInStones(J string, S string) int {
    rtn := 0
    for i:=0; i<len(S); i++ {
        for j:=0; j<len(J); j++ {
            if S[i] == J[j] {
                rtn++
            }
        }
    }
    return rtn;
}