import qrcode
from PIL import Image

# Function to generate QR code with a logo
def generate_qr_with_logo(link, logo_path, output_path, qr_size=10, logo_size_ratio=0.2):
    # Generate the QR code
    qr = qrcode.QRCode(
        version=1,
        error_correction=qrcode.constants.ERROR_CORRECT_H,
        box_size=qr_size,
        border=4,
    )
    qr.add_data(link)
    qr.make(fit=True)

    # Create an image from the QR code instance
    qr_img = qr.make_image(fill_color="black", back_color="white").convert('RGB')

    # Open the logo image
    logo = Image.open(logo_path)

    # Calculate the size of the logo
    qr_width, qr_height = qr_img.size
    logo_size = int(min(qr_width, qr_height) * logo_size_ratio)
    logo = logo.resize((logo_size, logo_size), Image.LANCZOS)

    # Calculate the position to place the logo
    pos = ((qr_width - logo_size) // 2, (qr_height - logo_size) // 2)

    # Paste the logo onto the QR code
    qr_img.paste(logo, pos, mask=logo)

    # Save the final QR code image
    qr_img.save(output_path)

# Example usage
link = "https://chatappbot.netlify.app/"
logo_path = "Arcadia.png"
output_path = "Qr.png"

generate_qr_with_logo(link, logo_path, output_path)
