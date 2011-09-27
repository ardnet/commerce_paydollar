Module: Commerce PayDollar
Author: Pratomo Ardianto


Description
===========
Integrates PayDollar as a payment gateway for Drupal Commerce.
Provides an options to select between live and dev environment of PayDollar,
and also provide an option to use 3D Transaction for the payment.
Currently support 4 currencies, which is USD, SGD, HKD and CNY.


Requirements
============

* Commerce



Installation
============

* Copy the 'commerce_paydollar' module directory in to your Drupal
  sites/all/modules directory as usual.

* Enable the module from the Modules > Commerce Payments section


Setup
=====

* Go to Commerce Admin Menu > Payment Methods and enable PayDollar.

* Edit PayDollar API and select whether you want to operate in the test or the
  live environment, input your username and hash password (provided by PayDollar)
  and select whether you want transactions to use 3D Transaction or not.


