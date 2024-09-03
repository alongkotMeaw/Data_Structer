// กำหนด interface Withdrawable
interface Withdrawable
{
    boolean withdraw(double amount);
}

// กำหนด abstract class BaseAccount
abstract class BaseAccount implements Withdrawable
{
    // Abstract method deposit
public
    abstract boolean deposit(double amount);

    // Implement withdraw method from Withdrawable interface
    @Override public abstract boolean withdraw(double amount);
}

// กำหนด abstract class Card
abstract class Card
{
    // Abstract method type
public
    abstract String type();

    // Abstract method discount
public
    abstract double discount();
}

// สร้าง subclass ของ BaseAccount คือ SavingAccount
class SavingAccount extends BaseAccount
{
private
    Card card;

    // Constructor ที่รับ Card เป็นพารามิเตอร์
public
    SavingAccount(Card card)
    {
        this.card = card;
    }

    // Implement deposit method
    @Override public boolean deposit(double amount)
    {
        // Logic for deposit
        System.out.println("Deposited: " + amount);
        return true; // Example return value
    }

    // Implement withdraw method
    @Override public boolean withdraw(double amount)
    {
        // Logic for withdraw
        System.out.println("Withdrew: " + amount);
        return true; // Example return value
    }

    // Method to get the Card object
public
    Card getCard()
    {
        return card;
    }
}

// สร้าง subclass ของ Card คือ DebitCard
class DebitCard extends Card
{
    // Implement type method
    @Override public String type()
    {
        return "Debit Card";
    }

    // Implement discount method
    @Override public double discount()
    {
        return 0.05; // Example discount value
    }
}

// ทดสอบการใช้งาน
public class Main
{
public
    static void main(String[] args)
    {
        Card myCard = new DebitCard();
        SavingAccount myAccount = new SavingAccount(myCard);

        myAccount.deposit(1000);
        myAccount.withdraw(200);

        System.out.println("Card type: " + myAccount.getCard().type());
        System.out.println("Card discount: " + myAccount.getCard().discount());
    }
}
