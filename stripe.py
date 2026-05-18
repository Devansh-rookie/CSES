import ast


def solve_invoice_reconciliation():
    try:
        input_line = input()
        data = ast.literal_eval(input_line)
        payment_str, invoices_list = data

        payment_parts = payment_str.split(",")
        payment_id = payment_parts[0]
        payment_amount = payment_parts[1]
        memo = payment_parts[2]

        target_invoice_id = memo.split(": ")[1]

        for invoice_str in invoices_list:
            invoice_parts = invoice_str.split(",")
            current_invoice_id = invoice_parts[0]
            due_date = invoice_parts[1]

            if current_invoice_id == target_invoice_id:
                print(
                    f"{payment_id} pays off {payment_amount} for {current_invoice_id} due on {due_date}"
                )
                break

    except EOFError:
        pass
    except Exception as e:
        print(f"An error occurred: {e}")


if __name__ == "__main__":
    solve_invoice_reconciliation()
