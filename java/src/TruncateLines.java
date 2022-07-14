import io.reactivex.rxjava3.core.Observable;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class TruncateLines {
    public static void main(String[] args) {
        Observable.fromStream(new BufferedReader(new InputStreamReader(System.in)).lines())
                .map(s -> s.length() < 10 ? s : s.substring(0, 10))
                .blockingSubscribe(System.out::println, Throwable::printStackTrace);
    }
}
