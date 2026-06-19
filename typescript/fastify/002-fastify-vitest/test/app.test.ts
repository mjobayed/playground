import { describe, expect, it } from "vitest";
import app from "../src/app.js";

describe("API test", () => {
  it("GET / - Should return OK", async () => {
    const response = await app.inject({
      method: "GET",
      url: "/",
    });

    expect(response.statusCode).toBe(200);
    expect(response.json()).toEqual({ message: "OK" });
  });
});
