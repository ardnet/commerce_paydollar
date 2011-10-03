<?php
/**
 * @file
 * Class to generate hash code.
 *
 * The code are example code that were get from PayDollar test site (https://test.paydollar.com).
 * 
 * How to get the code:
 * Register and login to the site.
 * Go to Support -> Developer Corner -> Direct Server Code, download the php code.
 */
interface PaydollarSecure {
  public function generatePaymentSecureHash($merchantId, $merchantReferenceNumber, $currencyCode, $amount, $paymentType, $secureHashSecret); 
  public function verifyPaymentDatafeed($src, $prc, $successCode, $merchantReferenceNumber, $paydollarReferenceNumber,
    $currencyCode, $amount, $payerAuthenticationStatus, $secureHashSecret, $secureHash
  );
}

class SHAPaydollarSecure implements PaydollarSecure {
  public function generatePaymentSecureHash($merchantId, $merchantReferenceNumber, $currencyCode, $amount, $paymentType, $secureHashSecret) {
    $buffer = $merchantId . '|' . $merchantReferenceNumber . '|' . $currencyCode . '|' . $amount . '|' . $paymentType . '|' . $secureHashSecret;
    return sha1($buffer);
  }

  public function verifyPaymentDatafeed($src, $prc, $successCode, $merchantReferenceNumber, $paydollarReferenceNumber,
    $currencyCode, $amount, $payerAuthenticationStatus, $secureHashSecret, $secureHash
  ) {
      $buffer = $src . '|' . $prc . '|' . $successCode . '|' . $merchantReferenceNumber . '|' . $paydollarReferenceNumber;
      $buffer .= '|' . $currencyCode . '|' . $amount . '|' . $payerAuthenticationStatus . '|' . $secureHashSecret;
      $verifyData = sha1($buffer);
      if ($secureHash == $verifyData) {
        return TRUE;
      }
      return FALSE;
  }
}

