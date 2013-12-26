import java.util.ArrayList;
import java.util.Set;

/**
 * Cracking the coding interview 7.5
 * Design the data structures for an online book reader system
 * Created by petrutrimbitas on 26/12/13.
 */

class Book {
    protected String title;
    private static Set<Book> books;
    public Book() {}
    public static Book findBook(String t) {return null;}
    public static void addBook(Book b) {books.add(b);}
}

class UserBook extends Book{
    private int position;
    public UserBook() {
        super();
        position=0;
    }
    public void setPosition(int np) {position=np;}
}

class User {
    private String name;
    private  ArrayList<UserBook> userBooks;
    private  static Set<User> users;

    public static void addUser(User u) {
        users.add(u);
    }

    public void addBook(Book b) {
        UserBook ub=new UserBook();
        ub.setPosition(0);
        userBooks.add(ub);
    }
}

public class BookReader {
}
