public class App {
    public static void search(String txt, String pat) {
        int slen = txt.length();
        int patlen = pat.length();

        for (int i = 0; i < slen - patlen; i++) {
            int j;
            for (j = 0; j < patlen; j++) {
                if (txt.charAt(i + j) != pat.charAt(j))
                    break;
            }
            if (j == patlen) {
                System.out.println("found at " + i);
                break;
            }
        }
    }

    public static void kmpSearch(String txt, String pat) {

    }

    public static void main(String[] args) throws Exception {
        String txt = "AABAACAADAABAAABAA";
        String pat = "AACAA";
        search(txt, pat);
        kmpSearch(txt, pat);
    }
}
