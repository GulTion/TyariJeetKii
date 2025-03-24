---
title: "Reading QR challenge | hackattic"
source: "https://hackattic.com/challenges/reading_qr"
author:
published:
created: 2024-12-20
description: "Those damn squares. They're everywhere."
tags:
  - "clippings"
---
# Reading QR

`10 points`

Connect to the problem endpoint, grab the image with a QR code from the returned `image_url`. The code contains a hyphen-formatted, numeric code.

Your task is to parse the QR code and submit the resulting code.

That's it, it's practically free points!

##### Getting the problem set

[`GET /challenges/**reading_qr**/problem**?access_token=a5919e4b3269c144`](https://hackattic.com/challenges/reading_qr/problem?access_token=a5919e4b3269c144)

Problem JSON format will be in the following format:

- `image_url`: URL to the image with the QR code

##### Submitting a solution

`POST /challenges/**reading_qr**/solve**?access_token=a5919e4b3269c144`

Solution JSON structure:

- `code`: the code contained in the QR

##### Why this challenge?

I had this one stashed away in git for ages. It's a pretty simple challenge, with the only twist being the rotation of the code - but there are many simple ways you can tackle that part. Even brute-force'y. Why not?